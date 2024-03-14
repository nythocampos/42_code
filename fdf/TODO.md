
# TODO:

## Important requirements

- Optimize image building
- Self-center the model
- Test with all maps
- Parcing
    - act like the example fdf
- Paint tall faces

## Less important requirements

Add a image updater

>steps to update the image
- modify the data // model, perspective...
- update projections using the data updated.
- rebuild the image
- push the image to the window

Check the memory leaks
    - t_state
    - t_models
    - t_mlx_data

Create a module to update the model
    - move
    - rotate
    - scale
    - select model
    - hidde model
    - add functions
    - add physics
    - add effects

Add a way to resize the model considering its dimentions

To refactor

- reduce get_cols_num: remove 1 variable

