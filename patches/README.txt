Contains post-processing patches for the generated code. The code generation
tool gets you close to, but not exactly at, the final code. There are some
manual changes that should be made. But these are in danger of being lost
every time new code is re-generated. 

To solve this problem, I've created patch files for Java and CPP, using
the Unix patch utility, described at http://en.wikipedia.org/wiki/Patch_(Unix)
Briefly, you generate a diff, then this diff can be applied to the 
generated file.

diff -u oldFile newFile > mods.diff  # -u tells diff to output unified diff format
patch oldFile mods.diff

The bash file in this directory runs patch using the patch files in
the java and cpp subdirectories. These patches are automatically
run if you're working on a unix-derivative development environment
and run the ant task to generate source code. If you're not running
on a Unix environment (Linux, OSX) you'll have to manually apply
the changes to the generated source. Under the Windows environment,
a pretty good choice is the Cygwin utilities, which supply a Unix 
environment under windows.

DMcG
