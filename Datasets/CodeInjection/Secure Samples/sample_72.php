<?php
$name = $_GET['name'] ?? 'Guest';
echo "Hello " . htmlspecialchars($name, ENT_QUOTES, 'UTF-8');
?>