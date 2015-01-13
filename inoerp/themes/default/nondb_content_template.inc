<div class="container">
 <div class="row">
  <div class="col-sm-8 blog-main">
   <div id="all_contents">
    <div id="content_top"></div>
    <div id="content">
     <div id="main">
      <div id="structure">
       <div id="content_divId">
        <!--    START OF FORM HEADER-->
        <div class="error"></div><div id="loading"></div>
        <?php
        echo (!empty($show_message)) ? $show_message : "";
        $f = new inoform();
        ?> 
        <!--    End of place for showing error messages-->
        <div id="form_all">
         <div id ="form_header">
          <div class='heading'> <?php echo $content_type->description; ?></div>
          <?php
          // echo pa($content_type); 
          if (method_exists($content_type, 'entry_form')) {
           $non_db_page = call_user_func(array($content_type, 'entry_form'), $_GET);
          } else {
           $non_db_page = ' <h1> No data found for the content type </h1>';
          }
          if (!empty($ownSubmitForm)) {
           echo $non_db_page;
          } else {
           ?>

           <form action=""  method="post" id="content_data"  name="content_data">
            <!--create empty form or a single id when search is not clicked and the id is referred from other content -->

            <!--End of Content-->
            <div> <?php // echo ino_attachement($file) ?> </div>
            <?php echo $non_db_page;
            echo $f->hidden_field_withId('non_db_content_type', $non_db_content_type); ?>
            <?php
            if ($access_level <= 3 && $mode == 9) {
             echo '<div id="save" class="submit"><input type="button" value="Submit" name="submit_content" class="button"></div>';
            }
           }
           ?>
          </form>
         </div> 
        </div>
       </div>
      </div>
     </div>
    </div>
    <div id="content_bottom"></div>
   </div>
  </div>
  <div class="col-sm-4 blog-sidebar">
   <div class="sidebar-module sidebar-module-inset">
    <div id="content_left"></div>
   </div>
   <div class="sidebar-module">
    <div id="content_right"></div>
   </div>

   <div class="sidebar-module">
    <div id="content_right_right"></div>
   </div>
  </div>
 </div>
</div>

<?php include_template('footer.inc') ?>
