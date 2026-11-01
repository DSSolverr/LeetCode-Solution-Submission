class Skiplist {
    struct Node {
        int val;
        vector<Node*> forward;

        Node(int v, int level) : val(v), forward(level, nullptr) {}
    };

    static const int MAX_LEVEL = 10;
    Node* head;
    uint32_t seed;   // xorshift seed

    // xorshift RNG
    uint32_t nextRand() {
        seed ^= seed << 13;
        seed ^= seed >> 17;
        seed ^= seed << 5;
        return seed;
    }

    int randomLevel() {
        int level = 1;
        while (level < MAX_LEVEL && (nextRand() & 1)) {
            level++;
        }
        return level;
    }

    void find(int target, vector<Node*>& preds, vector<Node*>& sucs) {
        Node* curr = head;
        for (int lvl = MAX_LEVEL - 1; lvl >= 0; lvl--) {
            while (curr->forward[lvl] && curr->forward[lvl]->val < target) {
                curr = curr->forward[lvl];
            }
            preds[lvl] = curr;
            sucs[lvl] = curr->forward[lvl];
        }
    }

public:
    Skiplist() : seed(123456789) {
        head = new Node(-1, MAX_LEVEL); // dummy head
    }

    bool search(int target) {
        vector<Node*> preds(MAX_LEVEL), sucs(MAX_LEVEL);
        find(target, preds, sucs);
        return sucs[0] && sucs[0]->val == target;
    }

    void add(int num) {
        vector<Node*> preds(MAX_LEVEL), sucs(MAX_LEVEL);
        find(num, preds, sucs);

        int level = randomLevel();
        Node* node = new Node(num, level);

        for (int i = 0; i < level; i++) {
            node->forward[i] = sucs[i];
            preds[i]->forward[i] = node;
        }
    }

    bool erase(int num) {
        vector<Node*> preds(MAX_LEVEL), sucs(MAX_LEVEL);
        find(num, preds, sucs);

        Node* target = sucs[0];
        if (!target || target->val != num) return false;

        for (int i = 0; i < target->forward.size(); i++) {
            if (preds[i]->forward[i] == target) {
                preds[i]->forward[i] = target->forward[i];
            }
        }

        delete target;
        return true;
    }
};