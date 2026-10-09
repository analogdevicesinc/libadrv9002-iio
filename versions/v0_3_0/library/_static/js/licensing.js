function activateButton(element) {
  document.getElementById("links_table").hidden = true;
  document.getElementById("submit").disabled = !element.checked;
}

function acceptedLicense(element) {
  alert("Thank you for accepting the license");
  document.getElementById("links_table").hidden = false;
  document.getElementById("licenseAcceptButtons").hidden = true;
}
