#!/usr/bin/perl

use strict;
use warnings;

use IO::All;

my ($in_fn, $out_fn) = @ARGV;

my $text = io->file($in_fn)->utf8->all();

my $dev_str = q#var devFolder = FS.createFolder('/', 'dev', true, true);#;
my $replace_str = q#var devFolder = FS.findObject('/dev') || FS.createFolder('/', 'dev', true, true);#;
if (not $text =~ s{^(\s*)\Q$dev_str\E(\s*)$}{$1$replace_str$2}ms)
{
    die "Cannot find '$dev_str' within file.";
}

# if (not
io->file($out_fn)->utf8->print($text);
