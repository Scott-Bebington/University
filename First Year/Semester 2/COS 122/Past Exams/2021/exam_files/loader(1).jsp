



//sessionkey
var var_key = "a5a3e649-5d87-11ec-8e2d-0a4acf953e0c";
var var_dashboard_url = "https://uop.eesysoft.com";
var var_loadfile = "https://uop.eesysoft.com/loadFile";
var var_style_path = "https://uop.eesysoft.com/resources";
var var_stamp = "20211215091818";
var var_eesy_build = "21450";
var var_eesy_dbUpdateCount = "1226";
var var_eesy_userUpdated = undefined;
var var_eesy_style_checksum = "d41d8cd98f00b204e9800998ecf8427e";
var var_show_tab_initial = false;
var var_show_tab = var_show_tab_initial;
var var_open_dashboard_in_new_window = false;
var var_tab_version = 3;
var var_proactive_version = 4;
var var_proactive_lms = "blackboard";
var var_proactive_dark = false;
var var_open_as_chat = false;
var var_moveable_tab = true;
var var_language = -1;
var var_uefMode = true;
var var_uefModeOriginal = !var_uefMode && (window.name === "classic-learn-iframe");
var var_uefModeOriginalUseUefSupportCenter = true;
var isUefOriginalSupportCenter = !var_uefMode && (var_uefModeOriginalUseUefSupportCenter || window.parent.var_uefModeOriginalUseUefSupportCenter);
var var_loadExpertTool = false;
var var_isExpertToolChromePlugin = false;
var eesyTemplates;
var waitforload = false;
var supportTabMinimized = undefined;
var scrollbarRightAdjust = '19px';
var supportTabMoveLimit = '50';
var eesy_minimizedTabWidth = '8px';
var eesy_maximizedTabWidth = '';
var attemptUnobscure = false;
var doNotLoadEngineForUserAgentPattern = 'not_in_use_05231;';
var var_eesy_hiddenHelpItems = undefined;
var var_eesy_sac = undefined;
var var_eesy_helpitemsSeen = undefined;
var var_user_map = {"isDebug":false,"userUpdatedStamp":"0","supportTabPosition":null,"reset_views_stamp":"","isShowTab":false,"languageId":-1,"isSupportTabMinimized":false,"id":648};
var var_instance_name = "uop";

function eesy_load_js(jsUrl) {
  var fileref = document.createElement("script");
  fileref.setAttribute("type", "text/javascript");
  fileref.setAttribute("src", jsUrl);
  document.getElementsByTagName("head")[0].appendChild(fileref);
}

eesy_load_js(var_dashboard_url + "/loader.js?u=" + var_eesy_build);
