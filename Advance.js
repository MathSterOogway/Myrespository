const searchInput_1 = document.getElementById('first-input');
const searchInput_2 = document.getElementById('second-input');
const searchInput_3 = document.getElementById('third-input');
const searchInput_4 = document.getElementById('fourth-input');
const button = document.getElementById('myButton');
button.addEventListener('click', function() {
    performGoogleSearch();
});

function performGoogleSearch() {
  const query_1 = searchInput_1.value;
  const query_2 = searchInput_2.value;
  const query_3 = searchInput_3.value;
  const query_4 = searchInput_4.value;
  if (query_4.trim() !== '' ) {
    const searchURL_4 = `https://www.google.com/search?as_q=${encodeURIComponent(query_1)}&as_epq=${encodeURIComponent(query_2)}&as_oq=${encodeURIComponent(query_3)}&as_eq=${encodeURIComponent(query_4)}`;
    window.location.href = searchURL_4;
  }
  else if (query_3.trim() !== '') {
    const searchURL_3 = `https://www.google.com/search?as_q=${encodeURIComponent(query_1)}&as_epq=${encodeURIComponent(query_2)}&as_oq=${encodeURIComponent(query_3)}`;
    window.location.href = searchURL_3;
  }
  else if (query_2.trim() !== '') {
    const searchURL_2 = `https://www.google.com/search?as_q=${encodeURIComponent(query_1)}&as_epq=${encodeURIComponent(query_2)}`;
    window.location.href = searchURL_2;
  }
  else if (query_1.trim() !== '') {
    const searchURL_1 = `https://www.google.com/search?as_q=${encodeURIComponent(query_1)}`;
    window.location.href = searchURL_1;
  }
}


