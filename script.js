function search() {
    const query = document.getElementById('searchBox').value;
    if (query.startsWith('http://') || query.startsWith('https://')) {
        window.location.href = query;
    } else if (query.includes('.')) {
        window.location.href = 'http://' + query;
    } else {
        window.location.href = 'https://www.google.com/search?q=' + encodeURIComponent(query);
    }
}
