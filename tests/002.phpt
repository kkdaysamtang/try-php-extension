--TEST--
test1() Basic test
--SKIPIF--
<?php
if (!extension_loaded('des_encrypt')) {
    echo 'skip';
}
?>
--FILE--
<?php
$ret = test1();

var_dump($ret);
?>
--EXPECT--
The extension des_encrypt is loaded and working!!!!!
NULL
