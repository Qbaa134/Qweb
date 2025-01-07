// Toggle sidebar
const sidebar = document.getElementById('sidebar');
document.getElementById('toggle-sidebar').addEventListener('click', () => {
    sidebar.classList.toggle('hidden');
});

// Search functionality
document.getElementById('search-btn').addEventListener('click', () => {
    const input = document.getElementById('search-input').value;
    if (input.startsWith('http')) {
        document.getElementById('browser-window').src = input;
    } else {
        document.getElementById('browser-window').src = `https://www.google.com/search?q=${input}`;
    }
});

// Tab switching for sidebar
document.getElementById('notes-tab').addEventListener('click', () => {
    showSection('notes-section');
});
document.getElementById('bookmarks-tab').addEventListener('click', () => {
    showSection('bookmarks-section');
});
document.getElementById('history-tab').addEventListener('click', () => {
    showSection('history-section');
});
document.getElementById('account-tab').addEventListener('click', () => {
    showSection('account-section');
});

function showSection(sectionId) {
    document.querySelectorAll('.section').forEach(section => section.classList.add('hidden'));
    document.getElementById(sectionId).classList.remove('hidden');
}

// Create account
const users = [];
document.getElementById('create-account').addEventListener('click', () => {
    const username = document.getElementById('username').value;
    const password = document.getElementById('password').value;

    if (username && password) {
        users.push({ username, password });
        document.getElementById('account-status').textContent = 'Account created successfully!';
    } else {
        document.getElementById('account-status').textContent = 'Please fill in all fields.';
    }
});
