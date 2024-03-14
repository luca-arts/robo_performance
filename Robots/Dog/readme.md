# DOG

runs Raspberry pi

## install

connect to the rpi:
1. vnc-viewer
2. make sure you're on the polymath network
3. connect to `dog.local`

```bash
cd /home/pi/robo_performance/Robots/Dog
python -m venv env
source env/bin/activate
pip install -r requirements.txt
```

## run python script

```bash
cd /home/pi/robo_performance/Robots/Dog
source env/bin/activate
python dog_server.py
```