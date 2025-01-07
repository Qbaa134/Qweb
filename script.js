// Obsługa przycisku szukania
document.getElementById('search-btn').addEventListener('click', () => {
    const url = document.getElementById('url-input').value;
    if (url) {
        document.getElementById('browser-window').src = url.startsWith('http') ? url : `https://${url}`;
    }
});

// Uruchamianie kodu w wybranym języku
document.getElementById('run-code').addEventListener('click', () => {
    const language = document.getElementById('language-select').value;
    const code = document.getElementById('console-log').value;

    try {
        if (language === 'javascript') {
            eval(code);
        } else {
            alert(`Running ${language} code is not supported yet.`);
        }
    } catch (err) {
        alert('Error: ' + err);
    }
});

// Dodawanie zakładek
const bookmarks = [];
document.getElementById('add-bookmark').addEventListener('click', () => {
    const url = document.getElementById('url-input').value;
    if (url) {
        bookmarks.push(url);
        updateBookmarkList();
    }
});

function updateBookmarkList() {
    const list = document.getElementById('bookmark-list');
    list.innerHTML = '';
    bookmarks.forEach((bookmark, index) => {
        const li = document.createElement('li');
        li.textContent = bookmark;
        list.appendChild(li);
    });
}
