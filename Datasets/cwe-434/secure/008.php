<?php
if(isset($_FILES['file'])) { $allowed=['png','jpg','jpeg']; $ext=pathinfo($_FILES['file']['name'],PATHINFO_EXTENSION); if(in_array(strtolower($ext),$allowed)){ $name=bin2hex(random_bytes(8)).'.'.$ext; move_uploaded_file($_FILES['file']['tmp_name'],'uploads/'.$name); echo 'OK'; } }
?>