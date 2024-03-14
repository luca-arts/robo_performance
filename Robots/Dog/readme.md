# DOG

runs Raspberry pi

to install rtpmidi: 

[source](https://github.com/davidmoreno/rtpmidid/releases)

```bash
wget https://github.com/davidmoreno/rtpmidid/releases/download/v23.10/rtpmidid_23.10_armhf.deb 
sudo dpkg -i rtpmidid_23.10_armhf.deb 
sudo apt -f install
rm rtpmidid_23.10_armhf.deb 
```

Adapt installation at `/etc/rtpmidid/default.ini`

`/home/pi/rtpmidid-23.12/build/src/rtpmidid --port 5004` to launch, but then how to capture further packages?

==> test capture midi messages on robot dog

# RAVELOX

https://github.com/ravelox/pimidi/

`sudo apt install autotools-dev autoconf automake pkgconfig avahi-devel avahi`

[tutorial?](https://blog.tarn-vedra.de/pimidi-box/)