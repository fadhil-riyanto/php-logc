--TEST--
log_trace() Simple variadic argc return 
--EXTENSIONS--
php_logger
--FILE--
<?php 
log_trace("abc % #%", "abc ghi123", "8");
?>
--EXPECT--
abc abc ghi123 #8