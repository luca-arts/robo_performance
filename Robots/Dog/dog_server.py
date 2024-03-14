from pymidi import server


class MidiConnectionsHandler(server.Handler):
    def on_peer_connected(self, peer):
        print('Peer connected: {}'.format(peer))

    def on_peer_disconnected(self, peer):
        print('Peer disconnected: {}'.format(peer))

    def on_midi_commands(self, peer, command_list):
        for command in command_list:
            if command.command == 'note_on':
                key = command.params.key
                velocity = command.params.velocity
                print('Someone hit the key {} with velocity {}'.format(key, velocity))


if __name__ == '__main__':
    myServer = server.Server([('0.0.0.0', 5004)])
    myServer.add_handler(MidiConnectionsHandler())
    myServer.serve_forever()
