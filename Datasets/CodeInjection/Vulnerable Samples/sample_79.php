<?php
// VULN: including a file path influenced by user can lead to code execution
$page = $_GET['page'] ?? 'home.php';
include($page); // CWE-94-ish (code execution via include)
?>