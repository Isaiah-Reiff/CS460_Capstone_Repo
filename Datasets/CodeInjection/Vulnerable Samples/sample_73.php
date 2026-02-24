<?php
// VULN: assert() evaluating string as PHP code (behavior varies by version/config)
$rule = $_POST['rule'] ?? '';
assert($rule); // CWE-94
echo "ok\n";
?>