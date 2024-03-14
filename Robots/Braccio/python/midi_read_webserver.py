import asyncio
import mido
import sys
from aiohttp import web

midi_file = None
spacebar_pressed = False


class midi_data:
    def __init__(self, midi_path):
        self.midi_path = midi_path
        self.midi_file = None
        self.read_midi_file()

    def read_midi_file(self):
        self.midi_file = mido.MidiFile(self.midi_path)

    def send_midi_data(self, connected_clients):
        for track in self.midi_file.tracks:
            for msg in track:
                midi_data = [msg.type >> 4, msg.type & 0xF, msg.channel - 1] + msg.data
                for client in connected_clients:
                    client.send_bytes(bytes(midi_data))
                asyncio.sleep(msg.time)
        spacebar_pressed = False


class webserver:
    def __init__(self, ip, port):
        self.ip = ip
        self.port = port
        self.connected_clients = set()

    async def hello(self, request):
        print("hello")
        return web.Response(text="Hello, world")

    async def handle_client(self, request):
        print("handle client")
        ws = web.WebSocketResponse()
        await ws.prepare(request)
        self.connected_clients.add(ws)
        print("Client connected")

        try:
            async for msg in ws:
                if msg.type == web.WT_MESSAGE:
                    pass
                else:
                    print("Client disconnected")
                    self.connected_clients.remove(ws)
                    return
        finally:
            print("Client disconnected")
            self.connected_clients.remove(ws)

    def run_server(self):
        app = web.Application()
        app.router.add_routes([web.get( '/ws', self.handle_client), web.get('/', self.hello)]) #web.get( '/', self.handle_client),
        web.run_app(app, host=self.ip, port=self.port)


#
# async def main_loop():
#     while True:
#         send_midi_data()
#         await asyncio.sleep(0.01)

async def handle_keyboard_input():
    while True:
        key_press = input("waiting for space bar")
        if key_press == " ":
            print("spacebar pressed")
            spacebar_pressed = True


if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: python midi_read_webserver.py <midi_file>")
        sys.exit(1)

    midi = midi_data(sys.argv[1])
    # if spacebar_pressed and connected_clients:
    ws = webserver('0.0.0.0', 8080)
    ws.run_server()
    print("here")


    # loop = asyncio.get_event_loop()
    # loop.create_task(main_loop())
    # loop.create_task(handle_keyboard_input())
    #
    # try:
    #     run_server('0.0.0.0', 8080)
    # except KeyboardInterrupt:
    #     pass
