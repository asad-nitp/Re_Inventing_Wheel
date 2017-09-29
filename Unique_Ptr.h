#pragma once
//author @asad_nitp

namespace Smart_Pointers {

	template<typename T>
	class Unique_Ptr {
		T* m_ptr;
	public:
		explicit Unique_Ptr(T* ptr = nullptr) noexcept
			: m_ptr(ptr) 
		{}

		~Unique_Ptr() {
			if (m_ptr != nullptr) {
				delete m_ptr;
			}
			m_ptr = nullptr;
		}

		Unique_Ptr(const Unique_Ptr&) = delete;
		Unique_Ptr& operator = (const Unique_Ptr&) = delete;

		Unique_Ptr(Unique_Ptr&& ob) noexcept {
			swap(ob);
		}
		Unique_Ptr& operator = (Unique_Ptr&& ob) noexcept {
			if (this != &ob) {
				swap(ob);
			}
			return *this;
		}

		explicit operator bool() {
			return m_ptr;
		}

		T* operator -> () const noexcept {
			return m_ptr;
		}

		T& operator * () const {
			return *m_ptr;
		}

		T* get() const noexcept{
			return m_ptr;
		}

		T* release() noexcept {
			T* ans = m_ptr;
			m_ptr = nullptr;
			return ans;
		}

		void reset(T* ptr = nullptr) {
			T* old = m_ptr;
			m_ptr = ptr;
			if (old != nullptr)
				delete old;
		}

		void swap(Unique_Ptr& ob) noexcept {
			using std::swap;
			swap(m_ptr,ob.m_ptr);
		}

	};
}
