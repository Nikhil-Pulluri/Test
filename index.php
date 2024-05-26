
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Document</title>
</head>
<body>
  <form action="index.php" method="post">
    <label>username:</label> <br>
    <input type="text" name="username"><br>
    <label>password</label>
    <input type="password" name="password"><br>
    <input type="submit" value="Log in">
  </form>
  
</body>
</html>

<?php
  foreach($_POST as $key => $value ){
    echo "{$key} = {$value}";
  }
?>

