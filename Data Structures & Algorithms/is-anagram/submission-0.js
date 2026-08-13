class Solution {
    /**
     * @param {string} s
     * @param {string} t
     * @return {boolean}
     */
    isAnagram(s, t) {
        return [...s].sort((a, b) => a.localeCompare(b)).join("") === [...t].sort((a, b) => a.localeCompare(b)).join("");
    }
}
