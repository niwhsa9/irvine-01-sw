# irvine-01-sw
irvine-01-sw software repository development tree

The irvine-01-sw project is the main entry point for irvine cubesat development

# Development Machine OS

The irvine-01-sw project should work on any modern Linux distribution, 64-bit or
32-bit.  You may install Ubuntu on a new/repurposed PC or in a 
virtual guest in [VirtualBox](https://www.virtualbox.org/).  The Ubuntu 14.04
ISO image may be downloaded from the [Ubuntu website](http://www.ubuntu.com/download/alternative-downloads)

# Ubuntu packages

To build irvine-01-sw, make sure you have `git`,`cmake` and the GNU C compiler installed:

```
sudo apt-get install git cmake gcc g++ cmake
```

# Ubuntu 16.04 (64-bit) Notes

For cross compiling to work, install the 32-bit compatibility libraries:

```
sudo dpkg --add-architecture i386
sudo apt-get update
sudo apt-get install libc6:i386 libstdc++6:i386
```

# irvine-01-sw project and toolchain install

The irvine-01-sw utilizes CMake to build the software.  You can build the
software for your host machine to test it, then cross compile it for the arm architecture in order to run it on the board.

To get started, retrieve the main software project and install the arm toolchain.
```
git clone https://github.com/irvinecubesat/irvine-01-sw
cd irvine-01-sw
make all-arm
```

This will build the arm binaries and put them under the `build-arm` directory.

You can type `make all ` to build x86 binaries under the `build` directory.

The first time you run the all or all-arm build, it will download and install
the toolchain.

Now, generate encryption keys for yourself.  Inside the irvine-01-sw project, type:
```
make genKeys
```

This will prompt you for a password which you will use for CubeSatNet VPN access.
After entering your password and confirmation password, email the resulting xxx-cubesatSetupRequest.txt.enc file to the CubeSatNet Administrator.

Once your account is set up, you will be able to connect to CubeSatNet using
the vpnConnect.sh script.

When the admin has updated the configuration with your certificate, type the following
in the irvine-01-sw project to allow you to successfuly build the buildroot project:
```
git pull
make authfile
```

*Note:  You can do all your programming in the irvine-01-sw project without
building the buildroot project, which builds the image to upload to the cubesat.*

If you would like to build the buildroot environment, go to the next step to
setup the buildroot environment.

# The irvine-01-cfg Project
The irvine-01-cfg github project has files that replace or modifies the
image generated by buildroot.  You use this project to customize the image.

To retrieve the irvine-01-cfg project:

```
git clone https://github.com/irvinecubesat/irvine-01-cfg
```

# The BuildRoot Project

The BuildRoot environment builds the image to upload to the 
cubesat board.  The buildroot environment is set up to build the irvine-01-sw
sources and install the irvine-01-cfg files into the fsw_image.

Be sure to follow the key generation procedure as described at the end of
irvine-01-sw project setup section.  

Make sure you have the necessary packages installed on your system:

```
 sudo apt-get install git bison g++ flex gettext texinfo libncurses5-dev
```
64-bit Ubuntu should also install the 32-bit libraries:
```
sudo apt-get install lib32z1 lib32ncurses5 lib32bz2-1.0
```
Note: The above instructions did not work for me on 64bit Kubuntu 16.10. If
you run into errors about apt-get being unable to locate the packages, 
follow these instructions instead
```
sudo dpkg --add-architecture i386
sudo apt-get update
sudo apt-get install libz1:i386 libncurses5:i386 libbz2-1.0:i386

Clone the irvinecubesat buildroot project from github:

```
git clone https://github.com/irvinecubesat/buildroot
```

Then make it:

```
cd buildroot
make
```
This will take a long time, and the end result will be under output/images

## Examining the image
The image will end up in the directory `buildroot/output/images/fsw_image`.
You can examine the directory structure of the image by looking at the
`fsw_image.rootfs.cpio` file:

Inside the buildroot/output/images/fsw_image directory, type:
```
mkdir tmp
cd tmp
cpio -i < ../fsw_image.rootfs.cpio
```
The cpio command will extract the rootfs into the tmp directory where you
can take a look at what is in the image.

# CalPoly Documentation
CalPoly Documentation is available at https://asof.atl.calpoly.edu/trac/polysat_documentation/wiki

*Note:  Do not follow the CalPoly buildroot instructions*

Use the above BuildRoot instructions instead.
