// BINARY SEARCH
int left = min(search_space), right = max(search_space);
while (left < right) {
    mid = left + (right - left) / 2;
    if (condition(mid))
        right = mid;
    else
        left = mid + 1;
}
return left;