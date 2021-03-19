# canvas-drawer

Implements a simple drawing api

TODO: Add a representative image for your project here

## How to build

*Windows*

Open git bash to the directory containing this repository.

```
canvas-drawer $ mkdir build
canvas-drawer $ cd build
canvas-drawer/build $ cmake -G "Visual Studio 16 2019" ..
canvas-drawer/build $ start Draw-2D.sln
```

Your solution file should contain two projects: `pixmap_art` and `pixmap_test`.
To run from the git bash command shell, 

```
canvas-drawer/build $ ../bin/Debug/draw_test
canvas-drawer/build $ ../bin/Debug/draw_art
```

*macOS*

Open terminal to the directory containing this repository.

```
canvas-drawer $ mkdir build
canvas-drawer $ cd build
canvas-drawer/build $ cmake ..
canvas-drawer/build $ make
```

To run each program from build, you would type

```
canvas-drawer/build $ ../bin/draw_test
canvas-drawer/build $ ../bin/draw_art
```

## Supported primitives

TODO: Document the custom primitives supported by your canvas class
![diagonal-line-1](https://user-images.githubusercontent.com/79232961/111728076-82496800-8842-11eb-9d45-314cfc5bc945.png)
![diagonal-line-2](https://user-images.githubusercontent.com/79232961/111728077-82e1fe80-8842-11eb-9be3-1d08501ffcbc.png)
![h-lessthan-w-line-1](https://user-images.githubusercontent.com/79232961/111728078-82e1fe80-8842-11eb-9720-127048a44c8e.png)
![h-lessthan-w-line-2](https://user-images.githubusercontent.com/79232961/111728079-82e1fe80-8842-11eb-80f5-1b8b7ae1c274.png)
![horizontal-line](https://user-images.githubusercontent.com/79232961/111728080-82e1fe80-8842-11eb-887f-d53839fbc4b1.png)
![line-color-interpolation](https://user-images.githubusercontent.com/79232961/111728082-82e1fe80-8842-11eb-9541-5af88c074d20.png)
![quad](https://user-images.githubusercontent.com/79232961/111728083-82e1fe80-8842-11eb-9bb8-607d4469dabc.png)
![triangle](https://user-images.githubusercontent.com/79232961/111728086-837a9500-8842-11eb-93bc-b9218060b6fb.png)
![vertical-line](https://user-images.githubusercontent.com/79232961/111728087-837a9500-8842-11eb-8004-520ba2cfe3bb.png)
![w-lessthan-h-line-1](https://user-images.githubusercontent.com/79232961/111728088-837a9500-8842-11eb-81c3-267d6932a151.png)
![w-lessthan-h-line-2](https://user-images.githubusercontent.com/79232961/111728089-837a9500-8842-11eb-96e7-862288264ebd.png)


## Results

TODO: Show artworks using your class
![rectangle](https://user-images.githubusercontent.com/79232961/111728085-82e1fe80-8842-11eb-8992-d3f48c5a3c95.png)
![artwork](https://user-images.githubusercontent.com/79232961/111728075-82496800-8842-11eb-8b69-3c45b0f6646a.png)
