import asyncio
import websockets

async def websocket_client():
    uri = "ws://192.168.0.188:8080/ws"  # Replace with your server's IP and port

    async with websockets.connect(uri) as websocket:
        print("Connected to websocket server")

        # Wait for MIDI data from the server
        while True:
            data = await websocket.recv()
            print(f"Received data: {data}")
            # You can process the received MIDI data here

# Run the websocket client
asyncio.get_event_loop().run_until_complete(websocket_client())
