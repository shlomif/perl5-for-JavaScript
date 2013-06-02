var Module = {
    preRun: function(input, output, error) {
        var dev = FS.createFolder('/', 'dev', true, false);
        FS.createDevice(dev, 'null', function (dev_in) { return; }, function () { return; });
    }
};
