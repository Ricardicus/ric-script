# Pytest test suite

Used to check that some of the samples
work after a new commit. 

# Run 

1. Requirements: Pytest, meson
2. Build the project with meson, name the buildfolder 'builddir'

```
# Stand in the root directory of this project
meson builddir
cd builddir
ninja
```

3. Stand in this testing directory (ric-script/tests)
4. Launch pytest:

``` 
# Running the test suite
pytest
```



