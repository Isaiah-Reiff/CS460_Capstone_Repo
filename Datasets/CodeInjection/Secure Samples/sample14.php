<?php
$action = $_POST['action'] ?? '';
$allowed = ['greet', 'sum'];
if (!in_array($action, $allowed)) { exit('bad'); }
if ($action == 'greet') echo "hi";
if ($action == 'sum') echo array_sum($_POST['values'] ?? []);
?>
