--TEST--
test1() Basic test
--EXTENSIONS--
php_logger
--FILE--
<?php
$ret = test1();

var_dump($ret);
?>
--EXPECT--
The extension php_logger is loaded and working!
NULL
