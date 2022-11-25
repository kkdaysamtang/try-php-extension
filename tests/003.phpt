--TEST--
des_encrypt_test2() Basic test
--SKIPIF--
<?php
if (!extension_loaded('des_encrypt')) {
    echo 'skip';
}
?>
--FILE--
<?php
var_dump(des_encrypt_test2());
var_dump(des_encrypt_test2('PHP'));
?>
--EXPECT--
string(11) "Hello World"
string(9) "Hello PHP"
