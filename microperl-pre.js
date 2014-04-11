var Module = eval('Module');
Module['noInitialRun'] = true;
Module['noExitRuntime'] = true;
Module['noFSInit'] = true;

Module.preRun.push( function () {
        /* No longer needed because emscripten already contains /dev/null */
        if (false) {
            var devFolder = FS.findObject("/dev") || FS.createFolder('/', 'dev', true, true);
            var null_in = function (all_input) { return;};
            var null_out = function () { return "5";};
            var ops = {isDevice: true, isFolder : false, input: null_in, output: null_out};
            FS.createDevice("/dev", "null", null_in, null_out);
        }
        FS.init(function(){ return input(); }, function(x) { output(x); }, function(x) { output(x); });
     }
);
Module.print = function(x) { output(x); };
