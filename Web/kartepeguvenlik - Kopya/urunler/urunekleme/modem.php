<?php
	set_time_limit(300);
	// check if a file was submitted
	if(isset($_FILES['foto']))
	{
	    try {
	    $msg= upload();  //this will upload your image
	    echo "<script>alert('İşlem başarı ile tamamlandı!')</script>";//$msg;  //Message showing success or failure.
	    }
	    catch(Exception $e) {
	    echo $e->getMessage();
	    echo 'Sorry, could not upload file';
	    }
	}

	// the upload function

	function upload() {
	    include "file_constants.php";
	    $maxsize = 10000000; //set to approx 10 MB

	    //check associated error code
	    if($_FILES['foto']['error']==UPLOAD_ERR_OK) {

	        //check whether file is uploaded with HTTP POST
	        if(is_uploaded_file($_FILES['foto']['tmp_name'])) {    

	            //checks size of uploaded image on server side
	            if( $_FILES['foto']['size'] < $maxsize) {  
	  
	               //checks whether uploaded file is of image type
	              //if(strpos(mime_content_type($_FILES['foto']['tmp_name']),"image")===0) {
	                 $finfo = finfo_open(FILEINFO_MIME_TYPE);
	                if(strpos(finfo_file($finfo, $_FILES['foto']['tmp_name']),"image")===0) {    

	                    // prepare the image for insertion
	                    $imgData =addslashes (file_get_contents($_FILES['foto']['tmp_name']));

	                    // put the image in the db...
	                    // database connection
	                    $conn = mysqli_connect($host, $user, $pass, $db) OR DIE (mysqli_error());

	                    // select the db
	                    /*mysqli_select_db ($db, ) OR DIE ("Unable to select db".mysqli_error());*/

	                    // our sql query
	                    $sql = "INSERT INTO modemler
	                    (foto,
	                     marka,
	                      model,
	                       tip,
	                        3g_4g_destegi,
	                         anten_gucu,
	                          anten_sayisi,
	                           degstirilebilir_anten,
	                            ethernet,
	                             ethernet_cikisi,
	                              fiber_baglanti,
	                               firewall,
	                                isletim_sistemi,
	                                 kablosuz_hizi,
	                                  router_ozelligi,
	                                   splitter,
	                                    turkce,
	                                     usb,
	                                      wireless)
	                    VALUES
	                    ('{$imgData}',
	                    '{$_POST['marka']}',
	                     '{$_POST['model']}',
	                      '{$_POST['tip']}',
	                       '{$_POST['3g_4g_destegi']}',
	                        '{$_POST['anten_gucu']}',
	                         '{$_POST['anten_sayisi']}',
	                          '{$_POST['degstirilebilir_anten']}',
	                           '{$_POST['ethernet']}',
	                            '{$_POST['ethernet_cikisi']}',
	                             '{$_POST['fiber_baglanti']}',
	                              '{$_POST['firewall']}',
	                               '{$_POST['isletim_sistemi']}',
	                                '{$_POST['kablosuz_hizi']}',
	                                 '{$_POST['router_ozelligi']}',
	                                  '{$_POST['splitter']}',
	                                   '{$_POST['turkce']}',
	                                    '{$_POST['usb']}',
	                                     '{$_POST['wireless']}');";

	                    // insert the image
	                    mysqli_query($conn, $sql) or die("Error in Query: " . mysqli_error($conn));
	                    $msg='<p>Image successfully saved in database with id ='. mysqli_insert_id($conn).' </p>';
	                }
	                else
	                    $msg="<p>Uploaded file is not an image.</p>";
	            }
	             else {
	                // if the file is not less than the maximum allowed, print an error
	                $msg='<div>File exceeds the Maximum File limit</div>
	                <div>Maximum File limit is '.$maxsize.' bytes</div>
	                <div>File '.$_FILES['foto']['name'].' is '.$_FILES['foto']['size'].
	                ' bytes</div><hr />';
	                }
	        }
	        else
	            $msg="File not uploaded successfully.";

	    }
	    else {
	        $msg= file_upload_error_message($_FILES['foto']['error']);
	    }
	    return $msg;
	}

	// Function to return error message based on error code

	function file_upload_error_message($error_code) {
	    switch ($error_code) {
	        case UPLOAD_ERR_INI_SIZE:
	            return 'The uploaded file exceeds the upload_max_filesize directive in php.ini';
	        case UPLOAD_ERR_FORM_SIZE:
	            return 'The uploaded file exceeds the MAX_FILE_SIZE directive that was specified in the HTML form';
	        case UPLOAD_ERR_PARTIAL:
	            return 'The uploaded file was only partially uploaded';
	        case UPLOAD_ERR_NO_FILE:
	            return 'No file was uploaded';
	        case UPLOAD_ERR_NO_TMP_DIR:
	            return 'Missing a temporary folder';
	        case UPLOAD_ERR_CANT_WRITE:
	            return 'Failed to write file to disk';
	        case UPLOAD_ERR_EXTENSION:
	            return 'File upload stopped by extension';
	        default:
	            return 'Unknown upload error';
	    }
	}
?>