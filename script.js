const result = document.querySelector(".result");

function detect() {
    const s1 = document.querySelector(".s1");
    const s2 = document.querySelector(".s2");

    let t1 = s1 ? s1.value : "";
    let t2 = s2 ? s2.value : "";

    result.textContent = lcs(t1, t2);
}

function lcs(t1, t2) {
    let n = t1.length;
    let m = t2.length;

    let letter = [];
    for (let i = 0; i < n + 1; i++) {
        letter[i] = [];
        for (let j = 0; j < m + 1; j++) {
            letter[i][j] = 0;
        }
    }

    let dir = [];
    for (let i = 0; i < n; i++) {
        dir[i] = [];
        for (let j = 0; j < m; j++) {
            dir[i][j] = 0;
        }
    }

    for (let i = 1; i < n + 1; i++) {
        for (let j = 1; j < m + 1; j++) {
            if (t1[i - 1] === t2[j - 1]) {
                letter[i][j] = letter[i - 1][j - 1] + 1;
                dir[i - 1][j - 1] = 0;
            } else if (letter[i - 1][j] >= letter[i][j - 1]) {
                letter[i][j] = letter[i - 1][j];
                dir[i - 1][j - 1] = 1;
            } else {
                letter[i][j] = letter[i][j - 1];
                dir[i - 1][j - 1] = -1;
            }
        }
    }

    let ans = "";
    let i = n;
    let j = m;

    while (i > 0 && j > 0) {
        if (dir[i - 1][j - 1] === 0) {
            ans = t1[i - 1] + ans;
            i--;
            j--;
        } else if (dir[i - 1][j - 1] === 1) {
            i--;
        } else {
            j--;
        }
    }

    return ans;
}
