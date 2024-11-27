--TEST--
log_trace() Simple variadic argc return 
--EXTENSIONS--
php_logger
--FILE--
<?php 
log_trace(8, 3, 5, 2, 1);
?>
--EXPECT--
current data val 5