<?php

    // configuration
    require("../includes/config.php");

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("register_form.php", ["title" => "Register"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // TODO
        if(empty($_POST["username"]))
        {
             apologize("You must provide a username."); 
        }
        else if(empty($_POST["password"]))
        {
            apologize("You must provide a password."); 
        }
        else if($_POST["password"] != $_POST["confirmation"])
        {
            apologize("password don't match");
            
        }
        $result =CS50::query("INSERT IGNORE INTO users (username, hash, cash) VALUES(?, ?, 10000.0000)", $_POST["username"], password_hash($_POST["password"], PASSWORD_DEFAULT));
        
        if($result==false)
        {
            apologize ("This username already exist");
        }
        else{
            $rows = CS50::query("SELECT LAST_INSERT_ID() AS id");
            $id = $rows[0]["id"];
            $_SESSION["id"] = $id;
            redirect("index.php");
        }
    }
    else{
        render("register_form.php",["Title"=>"Register"]);
    }

?>