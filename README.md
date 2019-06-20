# is-png - a minimalistic PNG identifier

This programme uses a simple heuristic to identify files that could be PNG
images.  It looks at the first four bytes of the file in question.  If those
bytes are "\x89PNG", the file might be a PNG image, so we return 0, otherwise
we return 1.

Note that, if anything goes wrong, e.g. the file could not be opened, the
`is-png` will be very conservative.  It has not seen evidence that the file is
not a PNG file, so it *might* be one.  Therefore, `is-png` returns 0 when an
error occurs.  If one wants to be sure that the file is a PNG image, one should
verify with some other tool:

```sh
is-png file.png && file file.png | grep -q PNG
```

In cases where it is important that the file in question *really* is a (valid)
PNG file, you should look for some PNG parser.  This tool is only for quickly
figuring out on which files running such a utility might be a good idea.
