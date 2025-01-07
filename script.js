// Prosta baza danych stron i fraz
const localData = [
    { title: 'GitHub', url: 'https://github.com', description: 'Platform for version control and collaboration' },
    { title: 'MDN Web Docs', url: 'https://developer.mozilla.org', description: 'Web development resources and documentation' },
    { title: 'W3Schools', url: 'https://www.w3schools.com', description: 'Learn web development with tutorials and references' },
    { title: 'QWeb', url: 'https://example.com/qweb', description: 'This is an example page for QWeb' },
];

// Funkcja wyszukiwania wewnętrznego
function search() {
    const query = document.getElementById('searchBox').value.toLowerCase();
    const resultsContainer = document.getElementById('searchResults');
    resultsContainer.innerHTML = ''; // Resetujemy poprzednie wyniki

    if (!query) {
        resultsContainer.innerHTML = '<p>Please enter a search phrase or URL.</p>';
        return;
    }

    const results = localData.filter(item => 
        item.title.toLowerCase().includes(query) || 
        item.description.toLowerCase().includes(query)
    );

    if (results.length > 0) {
        results.forEach(item => {
            const resultItem = document.createElement('div');
            resultItem.classList.add('result');
            resultItem.innerHTML = `
                <h3><a href="${item.url}" target="_blank">${item.title}</a></h3>
                <p>${item.description}</p>
            `;
            resultsContainer.appendChild(resultItem);
        });
    } else {
        resultsContainer.innerHTML = '<p>No results found.</p>';
    }
}
