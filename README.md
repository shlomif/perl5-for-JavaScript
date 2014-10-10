# Live

* http://www.shlomifish.org/microperl-web-repl-v1/repl.html

* Tested with Firefox 28, chromium-browser 34

* May not work on mobile browsers.

## About

This  is perl without CPAN/POSIX/XS/Bundled Modules, aka just
perl and none of the fluff. It is derived from the microperl
and miniperl build files of the perl-5.16.3 code.

## Installation

* Linux

```
make
make plutest
./plu -e "print 'hello world'"
```

* Emscripten (Console)

```
make -f Makefile_emcc CONSOLE=1
cat entry_point.js plu.js > plu.run.js
node plu.run.js virtual_file.pl
```

* Emscripten (for Web)

```
make -f Makefile_emcc
cp plu.js to web_repl/js/microperl.js
Open web_repl/repl.html in a browser !
```

There is also a CONSOLE=1 make option which generates
plu.console.js, for debugging.

## Shoutout

* http://kripken.github.io/lua.vm.js/lua.vm.js.html (for inspiration)

* https://github.com/themucker/ for doing some of the initial work on perl for JavaScript.

* Shlomi Fish (http://www.shlomifish.org/) from #perl (me) for later
  updates

## TODO

* Unit test emscripten code.
* Write limitations.
* Select a few CPAN modules for bundling.
* REPL (Read-Eval-Print Loop) oriented towards beginners.
* s/js/perl/ ? (Don't think so, but a possibility).
* Experiment with the perl source code for fun and profit !

## License

Artistic License 1 + GPLv1-or-above

