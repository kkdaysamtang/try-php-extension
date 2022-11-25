--TEST--
Check if des_encrypt is loaded
--SKIPIF--
<?php
if (!extension_loaded('des_encrypt')) {
    echo 'skip';
}
?>
--FILE--
<?php
echo 'The extension "des_encrypt" is available';
?>
--EXPECT--
The extension "des_encrypt" is available
