const clickableImage = document.getElementById('clickableImage');

clickableImage.addEventListener('click', function() {
  performGoogleImageSearch();
});
const searchInput = document.getElementById('searchInput');

searchInput.addEventListener('keydown', function(event) {
  if (event.key === 'Enter') {
    event.preventDefault(); // Prevent form submission
    performGoogleImageSearch();
  }
});

function performGoogleImageSearch() {
  const query = searchInput.value;
  if (query.trim() !== '') {
    const searchURL = `https://www.google.com/search?tbm=isch&q=${encodeURIComponent(query)}`;
    window.location.href = searchURL;
  }
}