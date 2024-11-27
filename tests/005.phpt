--TEST--
log_trace() Simple variadic argc return 
--EXTENSIONS--
php_logger
--FILE--
<?php 
log_trace(8);
?>
--EXPECT--
current data val 1