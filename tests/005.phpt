--TEST--
log_trace() Simple variadic argc return 
--EXTENSIONS--
php_logger
--FILE--
<?php 
log_trace(2);
?>
--EXPECTF--
Fatal error: Uncaught TypeError: log_trace(): Argument #1 must be string, int given in %s
Stack trace:
#0 %s(%d): log_trace(%d)
#1 {main}
  thrown in %s on line %d