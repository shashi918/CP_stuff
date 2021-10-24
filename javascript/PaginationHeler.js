//PaginationHelper
/*
For this exercise you will be strengthening your page-fu mastery. You will complete the PaginationHelper class, which is a utility class helpful for querying paging information related to an array.

The class is designed to take in an array of values and an integer indicating how many items will be allowed per each page. The types of values contained within the collection/array are not relevant.

The following are some examples of how this class is used:

var helper = new PaginationHelper(['a','b','c','d','e','f'], 4);
helper.pageCount(); //should == 2
helper.itemCount(); //should == 6
helper.pageItemCount(0); //should == 4
helper.pageItemCount(1); // last page - should == 2
helper.pageItemCount(2); // should == -1 since the page is invalid

// pageIndex takes an item index and returns the page that it belongs on
helper.pageIndex(5); //should == 1 (zero based index)
helper.pageIndex(2); //should == 0
helper.pageIndex(20); //should == -1
helper.pageIndex(-10); //should == -1
*/
class PaginationHelper {
    constructor(collection, itemsPerPage) {
        this.collection = collection;
        this.itemsPerPage = itemsPerPage;
    }
    itemCount() {
        let size = this.collection.length;
        return size;
    }
    pageCount() {
        let ans = parseInt(this.collection.length / this.itemsPerPage);
        if (this.collection.length / this.itemsPerPage == parseInt(this.collection.length / this.itemsPerPage))
            return ans;
        else return ans + 1;
    }
    pageItemCount(pageIndex) {
        if (pageIndex == 0)
            return 1 * this.itemsPerPage;
        else {
            if (this.pageCount() - 1 < pageIndex)
                return -1;
            else if ((pageIndex + 1) * this.itemsPerPage > this.collection.length)
                return this.collection.length - (pageIndex) * this.itemsPerPage;
            else return this.itemsPerPage;
        }
    }
    pageIndex(itemIndex) {
        if (this.collection.length == 0)
            return -1;
        if (itemIndex > this.collection.length || itemIndex < 0)
            return -1;
        let count = 0;
        let items_per_page = this.itemsPerPage;
        let temp = itemIndex;
        while (temp > items_per_page) {
            count++;
            items_per_page *= 2;
        }
        return count;
    }
}

var helper = new PaginationHelper(['a', 'b', 'c', 'd', 'e', 'f'], 4);
console.log(helper.pageCount()); //should == 2
console.log(helper.itemCount()); //should == 6
console.log(helper.pageItemCount(0)); //should == 4
console.log(helper.pageItemCount(1)); // last page - should == 2
console.log(helper.pageItemCount(2)); // should == -1 since the page is invalid

// pageIndex takes an item index and returns the page that it belongs on
console.log(helper.pageIndex(5)); //should == 1 (zero based index)
console.log(helper.pageIndex(2)); //should == 0
console.log(helper.pageIndex(20)); //should == -1
console.log(helper.pageIndex(-10));

