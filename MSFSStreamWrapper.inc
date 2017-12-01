<?php

class MSFSStreamWrapper implements DrupalStreamWrapperInterface {

  /**
   * Instance URI referenced as "<scheme>://key".
   *
   * @var string
   */
  protected $uri = NULL;

  /**
   * Directory listing used by the dir_* methods.
   *
   * @var array
   */
  protected $dir = NULL;

  public function __construct() {
//    $this->server = array();
  }


  public function chmod($mode) {
    return TRUE;
  }

  public function dir_closedir() {
    unset($this->dir);
    return TRUE;
  }

  public function dir_opendir($uri, $options) {
    // TODO: Implement dir_opendir() method.
    $b = 1;
  }

  public function dir_readdir() {
    // TODO: Implement dir_readdir() method.
    $b = 1;
  }

  public function dir_rewinddir() {
    reset($this->dir);
    return TRUE;
  }

  public function dirname($uri = NULL) {
    if (!isset($uri)) {
      $uri = $this->uri;
    }
    $scheme = file_uri_scheme($uri);
    $dirname = dirname(file_uri_target($uri));


    if ($dirname == '.') {
      $dirname = '';
    }

    return "$scheme://$dirname";
  }

  public function getExternalUrl() {
    // TODO: Implement getExternalUrl() method.
    $b = 1;
  }

  public function mkdir($uri, $mode, $options) {
    // TODO: Implement mkdir() method.
    $b = 1;
  }

  public function realpath() {
    return FALSE;
  }

  public function rename($from_uri, $to_uri) {
    // TODO: Implement rename() method.
    $b = 1;
  }

  public function rmdir($uri, $options) {
    // TODO: Implement rmdir() method.
    $b = 1;
  }

  public function setUri($uri) {
    $this->uri = $uri;
  }

  public function getUri() {
    return $this->uri;
  }

  public function stream_close() {
    // TODO: Implement stream_close() method.
    $b = 1;
  }

  public function stream_eof() {
    // TODO: Implement stream_eof() method.
    $b = 1;
  }

  public function stream_open($uri, $mode, $options, &$opened_url) {
    // TODO: Implement stream_open() method.
    $b = 1;
  }

  public function stream_lock($operation) {
    // TODO: Implement stream_lock() method.
    $b = 1;
  }

  public function stream_read($count) {
    // TODO: Implement stream_read() method.
    $b = 1;
  }

  public function stream_write($data) {
    // TODO: Implement stream_write() method.
    $b = 1;
  }

  public function stream_seek($offset, $whence) {
    // TODO: Implement stream_seek() method.
    $b = 1;
  }

  public function stream_flush() {
    // TODO: Implement stream_flush() method.
    $b = 1;
  }

  public function stream_tell() {
    // TODO: Implement stream_tell() method.
    $b = 1;
  }

  public function stream_stat() {
    // TODO: Implement stream_stat() method.
    $b = 1;
  }

  public function unlink($uri) {
    // TODO: Implement unlink() method.
    $b = 1;
  }

  public function url_stat($uri, $flags) {
    // TODO: Implement url_stat() method.
    $b = 1;
  }

  public static function getMimeType($uri, $mapping = NULL) {
    // TODO: Implement getMimeType() method.
    $b = 1;
  }

  /**
   * Gets the path that the wrapper is responsible for.
   *
   * This function isn't part of DrupalStreamWrapperInterface, but the rest
   * of Drupal calls it as if it were, so we need to define it.
   *
   * @return string
   *   The empty string. Since this is a remote stream wrapper,
   *   it has no directory path.
   */
  public function getDirectoryPath() {
    return '';
  }

}