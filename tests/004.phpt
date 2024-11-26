--TEST--
test_f() Basic test
--EXTENSIONS--
php_logger
--FILE--
<?php
var_dump(test_f(5));
?>
--EXPECT--
float(10)
