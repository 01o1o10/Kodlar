<?php

 set_time_limit(300);
 $tablo = $_POST['tablo'];
 include "file_constants.php";
 // just so we know it is broken
 error_reporting(E_ALL);
 // some basic sanity checks
     //connect to the db
     $link = mysqli_connect($host, $user, $pass, $db)
     or die("Could not connect: " . mysqli_error());

     // select our database
     //mysql_select_db("$db") or die(mysql_error());

     // get the image from the db
     $sql = "SELECT * FROM ".$tablo.";";

     // the result of the query
     $result = mysqli_query($link ,$sql) or die($tablo."Invalid query: " . mysqli_error($link));

     // set the header for the image
     //header("Content-type: image/jpeg");
     echo '<table style="width: 100%; height: auto;">';
     $i = 1;
     while(1){
          echo '<tr style="width:100%; height:auto;">';
          for($i = 1; $i <=4; $i++){
               $row = mysqli_fetch_array($result);
               if($row == false){
                    break;
               }
               echo '<td style="display: block;
                         background-color: white;
                         margin: 2% 1%;
                         width: 23%;
                         height: 270px;
                         float: left;
                         box-shadow: 0 8px 16px 0 rgba(0, 0, 0, 0.4), 0 12px 40px 0 rgba(0, 0, 0, 0.38);
                         text-align: center;">';
               echo '<img src="data:image/jpeg;base64,'.base64_encode($row['foto']).'" style="width:100%; height: 200px"/>';
               echo '<hr style="margin: 0; height: 0.5px; background-color: gray;">
                    <div style="padding: 10px;">
                         <p style="margin: auto; text-align: center;">
                              <b>'.$row['marka'].'</br>'.$row['model'].'</b>
                         </p>
                    </div>';
               echo '</td>';
          }
          echo '</tr>';
          if($i !== 5){
               break;
          }
     }
     echo '</table>';

     // close the db link
     mysqli_close($link);
?>