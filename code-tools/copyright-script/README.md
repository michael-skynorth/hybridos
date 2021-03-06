# Replace file header scripts

**Author:** Gerhard Gappmeier <gerhard.gappmeier[at]ascolab.com> 
**License:** These files are distributed under the terms of the GPL. See the LICENSE.md file for more information.

## Description
 
This scripts can replace file headers from C/C++/JAVA header and source files. Often it's necessary to replace the license conditions in multiple source files, update the copyright year, or simply make all file headers consistent. This can be a lot of work, so that's why I wrote this scripts.

## How it works

The BASH script replace_header.sh is a simple wrapper that executes the AWK script remove_header.awk which implements a basic state machine for recognizing C/C++/JAVA comments ```("// ...", "/* ... */)```. All comments at the beginning of the file - also when spanning over multiple lines - are ignored until the first line without comment is reached. The AWK file ignores all this comments, and prints the rest of the file unchanged. The BASH script creates a new file with your new header.template and adds your code without the old file header to the newly created file. Afterwards it copies the new file over the old one.

## Install 

Just clones the files of this repository into a directory and edit the file ```header.template``` to fit your needs. That's it.

## Usage 

```
./<your_installation_path>/replace_header.sh <file>
```

This replaces only the header of the given file. That's how it works, but the power comes in combination with the find utility. See the following example how it works together with find.

## Example

Recursively change all header files
```
$ cd ~/your/source/dir
$ find . -name "*.h" # verify the output to check what is going to be changed.
$ find . -name "*.h" -exec /<your_installation_path>/replace_header.sh {} \; # Now replace them all.
```

See ```$man find``` for more information on how to use find.

## ATTENTION

This script changes the files in place, makes no backups, no warnings, no prompts. You should commit all changes to your version control system before using it, or at least backup your files. (You should really use a VCS like SVN, GIT, CVS, etc.) **USE THIS ON YOUR OWN RISK!** This scripts are provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.

