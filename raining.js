const searchInput = document.getElementById('searchInput');

searchInput.addEventListener('keydown', function(event) {
  if (event.key === 'Enter') {
    event.preventDefault(); // Prevent form submission
    performGoogleSearch();
  }
});

function performGoogleSearch() {
  const query = searchInput.value;
  if (query.trim() !== '') {
    const searchURL = `https://www.google.com/search?q=${encodeURIComponent(query)}`;
    window.location.href = searchURL;
  }
}




