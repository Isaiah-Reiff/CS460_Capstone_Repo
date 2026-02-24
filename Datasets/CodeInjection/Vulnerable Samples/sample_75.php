<?php
// VULN: create_function from user input (deprecated/removed in newer PHP)
$body = $_GET['body'] ?? 'return 1;';
$f = create_function('', $body); // CWE-94
echo $f();
?>