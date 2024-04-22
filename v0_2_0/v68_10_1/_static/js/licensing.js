function acceptedLicense(element) {
  alert("Thank you for accepting the license")
  document.getElementById("links_table").hidden = false;
  document.getElementById("licenseAcceptButtons").hidden = true;
}

function disableSubmit() {
  document.getElementById("submit").disabled = true;
}

function activateButton(element) {
  document.getElementById("links_table").hidden = true;
  if (element.checked) {
    document.getElementById("submit").disabled = false;
  } else {
    document.getElementById("submit").disabled = true;
  }
}
