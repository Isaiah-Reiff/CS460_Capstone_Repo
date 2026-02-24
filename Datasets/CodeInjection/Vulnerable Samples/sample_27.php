<?php
$code = $_POST['calc'] ?? "";
$result = eval("return " . $code . ";");   // executes attacker input
echo $result;
?>