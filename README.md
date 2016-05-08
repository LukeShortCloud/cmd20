# cmd20
### Version: 0.3.0-dev

A free and open source dice roller CLI utility programmed in C++.

## Usage
Automatic Install:
```
# ./configure
# make && make install
```

Manual Install:
```
# g++ ./cmd20.cpp -o cmd20; cp cmd20 /usr/local/bin/
# cp ./man/cmd20.1 /usr/share/man/man1/
```

Example:
```
# cmd20 -n 82
Rolling a 82 sided die...
You rolled a 25
# cmd20 -q -n 8
6
```

Help:
```
# cmd20 -h
OR
# man cmd20
```


## License
This software is licensed under the GPLv3. More information about this can be found in the included "LICENSE" file or online at: http://www.gnu.org/licenses/gpl-3.0.en.html



